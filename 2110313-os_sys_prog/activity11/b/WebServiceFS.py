#!/usr/bin/env python3

# 2110313 Operating System - Activity 11(b)
# FUSE filesystem backed by a web service.
#
# Filesystem contents:
#   /participation
#
# Reading /participation performs HTTP GET to status.php.
# Appending "studentid:name:email" to /participation performs HTTP POST to
# checkIn.php with fields studentid, name, and email.

import errno
import os
import stat

import fuse
from fuse import Fuse

import requests

fuse.fuse_python_api = (0, 2)

STATUS_URL = 'https://mis.cp.eng.chula.ac.th/krerk/teaching/2022s2-os/status.php'
CHECKIN_URL = 'https://mis.cp.eng.chula.ac.th/krerk/teaching/2022s2-os/checkIn.php'
PARTICIPATION = '/participation'


class MyStat(fuse.Stat):
    def __init__(self):
        self.st_mode = 0
        self.st_ino = 0
        self.st_dev = 0
        self.st_nlink = 0
        self.st_uid = os.getuid()
        self.st_gid = os.getgid()
        self.st_size = 0
        self.st_atime = 0
        self.st_mtime = 0
        self.st_ctime = 0


def get_status():
    """GET participation status and return it as bytes."""
    r = requests.get(STATUS_URL)
    r.raise_for_status()
    return r.content

def post_checkin(buf):
    """POST one check-in record.  Input format: studentid:name:email."""
    if isinstance(buf, bytes):
        text = buf.decode('utf-8')
    else:
        text = buf

    text = text.strip()
    raw = text.split(':', 2)
    if len(raw) != 3:
        raise ValueError('append data must be studentid:name:email')

    params = {
        'studentid': raw[0],
        'name': raw[1],
        'email': raw[2],
    }
    r = requests.post(CHECKIN_URL, data=params)
    r.raise_for_status()

class WebServiceFS(Fuse):
    def getattr(self, path):
        st = MyStat()

        if path == '/':
            st.st_mode = stat.S_IFDIR | 0o755
            st.st_nlink = 2
            return st

        if path == PARTICIPATION:
            st.st_mode = stat.S_IFREG | 0o666
            st.st_nlink = 1
            # Size is dynamic, but some programs skip read() when size is 0.
            # Report the current remote size so `cat mnt/participation` reads it.
            try:
                st.st_size = len(get_status())
            except Exception:
                st.st_size = 1024 * 1024
            return st

        return -errno.ENOENT

    def readdir(self, path, offset):
        if path != '/':
            return -errno.ENOENT

        for name in '.', '..', PARTICIPATION[1:]:
            yield fuse.Direntry(name)

    def open(self, path, flags):
        if path != PARTICIPATION:
            return -errno.ENOENT

        # Allow reading and appending.  Refuse overwriting with >file.
        accmode = flags & os.O_ACCMODE
        if accmode in (os.O_WRONLY, os.O_RDWR) and not (flags & os.O_APPEND):
            return -errno.EACCES

        return 0

    def read(self, path, size, offset):
        if path != PARTICIPATION:
            return -errno.ENOENT

        try:
            content = get_status()
        except Exception as e:
            return ('GET failed: %s\n' % e).encode('utf-8')

        return content[offset:offset + size]

    def write(self, path, buf, offset):
        if path != PARTICIPATION:
            return -errno.ENOENT

        try:
            post_checkin(buf)
        except ValueError:
            return -errno.EINVAL
        except Exception:
            return -errno.EIO

        return len(buf)

    def truncate(self, path, size):
        if path != PARTICIPATION:
            return -errno.ENOENT
        # Do not truncate remote data; support append-only semantics.
        return 0


def main():
    usage = """
Web service backed FUSE filesystem
""" + Fuse.fusage

    server = WebServiceFS(version="%prog " + fuse.__version__,
                          usage=usage,
                          dash_s_do='setsingle')
    server.parse(errex=1)
    server.main()


if __name__ == '__main__':
    main()

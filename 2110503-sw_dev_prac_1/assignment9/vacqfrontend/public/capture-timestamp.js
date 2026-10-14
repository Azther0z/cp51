if (new URLSearchParams(window.location.search).has('captureTimestamp')) {
  const timestampBadge = document.createElement('div')
  timestampBadge.setAttribute('role', 'note')
  timestampBadge.setAttribute('aria-label', 'Screenshot capture date and time')

  const updateTimestamp = () => {
    const formatted = new Intl.DateTimeFormat('en-GB', {
      dateStyle: 'medium',
      timeStyle: 'medium',
      timeZone: 'Asia/Bangkok',
    }).format(new Date())
    timestampBadge.textContent = `Captured: ${formatted} (Asia/Bangkok)`
  }

  Object.assign(timestampBadge.style, {
    position: 'fixed',
    right: '14px',
    bottom: '14px',
    zIndex: '2147483647',
    padding: '8px 12px',
    borderRadius: '6px',
    background: 'rgba(17, 17, 17, 0.94)',
    color: '#fff',
    font: '600 14px system-ui, sans-serif',
    boxShadow: '0 2px 8px rgba(0, 0, 0, 0.3)',
  })

  const mountTimestamp = () => {
    updateTimestamp()
    document.body.appendChild(timestampBadge)
    window.setInterval(updateTimestamp, 1000)
  }

  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', mountTimestamp, { once: true })
  } else {
    mountTimestamp()
  }
}

import { useDispatch, useSelector } from 'react-redux'
import { Link, useNavigate } from 'react-router-dom'
import { FaSignInAlt, FaSignOutAlt, FaUser } from 'react-icons/fa'
import { logout } from '../features/auth/authSlice'

function Header() {
  const dispatch = useDispatch()
  const navigate = useNavigate()
  const user = useSelector((state) => state.auth.user)

  const onLogout = async () => {
    await dispatch(logout())
    navigate('/')
  }

  return (
    <header className='header'>
      <Link className='logo' to='/'>Support Desk</Link>
      <ul>
        {user ? (
          <>
            <li className='user-name'>Hello, {user.name}</li>
            <li>
              <button className='btn btn-sm' type='button' onClick={onLogout}>
                <FaSignOutAlt aria-hidden='true' />
                Logout
              </button>
            </li>
          </>
        ) : (
          <>
            <li>
              <Link to='/login'>
                <FaSignInAlt aria-hidden='true' /> Login
              </Link>
            </li>
            <li>
              <Link to='/register'>
                <FaUser aria-hidden='true' /> Register
              </Link>
            </li>
          </>
        )}
      </ul>
    </header>
  )
}

export default Header

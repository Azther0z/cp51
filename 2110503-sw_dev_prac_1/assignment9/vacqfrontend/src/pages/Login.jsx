import { useEffect, useState } from 'react'
import { useDispatch, useSelector } from 'react-redux'
import { useNavigate } from 'react-router-dom'
import { toast } from 'react-toastify'
import { FaSignInAlt } from 'react-icons/fa'
import { login, reset } from '../features/auth/authSlice'

function Login() {
  const [formData, setFormData] = useState({ email: '', password: '' })
  const dispatch = useDispatch()
  const navigate = useNavigate()
  const { user, isLoading, isError, isSuccess, message } = useSelector(
    (state) => state.auth,
  )

  useEffect(() => {
    dispatch(reset())
  }, [dispatch])

  useEffect(() => {
    if (isError) toast.error(message)
    if (isSuccess || user) navigate('/')
  }, [isError, isSuccess, user, message, navigate])

  const onChange = (event) => {
    setFormData((previous) => ({
      ...previous,
      [event.target.name]: event.target.value,
    }))
  }

  const onSubmit = (event) => {
    event.preventDefault()
    dispatch(login(formData))
  }

  return (
    <>
      <section className='heading'>
        <h1>
          <FaSignInAlt aria-hidden='true' /> Login
        </h1>
        <p>Please login to get support</p>
      </section>
      <section className='form'>
        <form onSubmit={onSubmit}>
          <div className='form-group'>
            <label htmlFor='email'>Email</label>
            <input
              type='email'
              id='email'
              name='email'
              value={formData.email}
              onChange={onChange}
              placeholder='Enter your email'
              autoComplete='email'
              required
            />
          </div>
          <div className='form-group'>
            <label htmlFor='password'>Password</label>
            <input
              type='password'
              id='password'
              name='password'
              value={formData.password}
              onChange={onChange}
              placeholder='Enter your password'
              autoComplete='current-password'
              required
            />
          </div>
          <button className='btn btn-block' type='submit' disabled={isLoading}>
            {isLoading ? 'Please wait…' : 'Submit'}
          </button>
        </form>
      </section>
    </>
  )
}

export default Login

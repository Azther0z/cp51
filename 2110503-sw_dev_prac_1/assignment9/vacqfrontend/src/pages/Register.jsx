import { useEffect, useState } from 'react'
import { useDispatch, useSelector } from 'react-redux'
import { useNavigate } from 'react-router-dom'
import { toast } from 'react-toastify'
import { FaUser } from 'react-icons/fa'
import { register, reset } from '../features/auth/authSlice'

function Register() {
  const [formData, setFormData] = useState({
    name: '',
    email: '',
    password: '',
    password2: '',
  })
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
    if (formData.password !== formData.password2) {
      toast.error('Passwords do not match')
      return
    }

    dispatch(
      register({
        name: formData.name,
        email: formData.email,
        password: formData.password,
        role: 'user',
      }),
    )
  }

  return (
    <>
      <section className='heading'>
        <h1>
          <FaUser aria-hidden='true' /> Register
        </h1>
        <p>Please create an account</p>
      </section>
      <section className='form'>
        <form onSubmit={onSubmit}>
          <div className='form-group'>
            <label htmlFor='name'>Name</label>
            <input
              type='text'
              id='name'
              name='name'
              value={formData.name}
              onChange={onChange}
              placeholder='Enter your name'
              autoComplete='name'
              required
            />
          </div>
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
              autoComplete='new-password'
              minLength={6}
              required
            />
          </div>
          <div className='form-group'>
            <label htmlFor='password2'>Confirm password</label>
            <input
              type='password'
              id='password2'
              name='password2'
              value={formData.password2}
              onChange={onChange}
              placeholder='Confirm your password'
              autoComplete='new-password'
              minLength={6}
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

export default Register

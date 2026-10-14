import axios from 'axios'

const API_URL = import.meta.env.VITE_API_URL || '/api/v1/auth'

const saveSession = (responseData) => {
  const { _id, name, email, token } = responseData
  const session = { user: { _id, name, email }, token }
  localStorage.setItem('user', JSON.stringify(session))
  return session
}

const register = async (userData) => {
  const response = await axios.post(`${API_URL}/register`, userData)
  console.log(response.data)
  return saveSession(response.data)
}

const login = async (userData) => {
  const response = await axios.post(`${API_URL}/login`, userData)
  console.log(response.data)
  return saveSession(response.data)
}

const logout = () => {
  localStorage.removeItem('user')
}

const authService = { register, login, logout }

export default authService

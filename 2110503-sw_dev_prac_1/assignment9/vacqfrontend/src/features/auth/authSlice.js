import { createAsyncThunk, createSlice } from '@reduxjs/toolkit'
import authService from './authService'

const getStoredSession = () => {
  try {
    const stored = JSON.parse(localStorage.getItem('user') || 'null')
    return stored?.user && stored?.token ? stored : null
  } catch {
    return null
  }
}

const storedSession = getStoredSession()

const initialState = {
  user: storedSession?.user || null,
  token: storedSession?.token || null,
  isError: false,
  isSuccess: false,
  isLoading: false,
  message: '',
}

const errorMessage = (error) =>
  error.response?.data?.message ||
  error.response?.data?.msg ||
  error.message ||
  'Unable to complete the request. Please try again.'

const redactAuthData = (userData) => ({
  ...(userData.name !== undefined && { name: '[redacted]' }),
  ...(userData.email !== undefined && { email: '[redacted]' }),
  ...(userData.password !== undefined && { password: '[redacted]' }),
  ...(userData.role !== undefined && { role: userData.role }),
})

export const register = createAsyncThunk(
  'auth/register',
  async (userData, thunkAPI) => {
    try {
      const session = await authService.register(userData)
      return session
    } catch (error) {
      return thunkAPI.rejectWithValue(errorMessage(error))
    }
  },
)

export const login = createAsyncThunk(
  'auth/login',
  async (userData, thunkAPI) => {
    try {
      const session = await authService.login(userData)
      return session
    } catch (error) {
      return thunkAPI.rejectWithValue(errorMessage(error))
    }
  },
)

export const logout = createAsyncThunk('auth/logout', async () => {
  authService.logout()
})

const authSlice = createSlice({
  name: 'auth',
  initialState,
  reducers: {
    reset: (state) => {
      state.isError = false
      state.isSuccess = false
      state.isLoading = false
      state.message = ''
    },
  },
  extraReducers: (builder) => {
    const addPending = (thunk) =>
      builder.addCase(thunk.pending, (state) => {
        state.isLoading = true
        state.isError = false
        state.isSuccess = false
        state.message = ''
      })

    const addFulfilled = (thunk) =>
      builder.addCase(thunk.fulfilled, (state, action) => {
        state.isLoading = false
        state.isSuccess = true
        state.user = action.payload.user
        state.token = action.payload.token
      })

    const addRejected = (thunk) =>
      builder.addCase(thunk.rejected, (state, action) => {
        state.isLoading = false
        state.isError = true
        state.message = action.payload || action.error.message
      })

    addPending(register)
    addFulfilled(register)
    addRejected(register)
    addPending(login)
    addFulfilled(login)
    addRejected(login)
    builder.addCase(logout.fulfilled, (state) => {
      state.user = null
      state.token = null
      state.isSuccess = false
      state.isError = false
      state.message = ''
    })
  },
})

export const { reset } = authSlice.actions
export default authSlice.reducer

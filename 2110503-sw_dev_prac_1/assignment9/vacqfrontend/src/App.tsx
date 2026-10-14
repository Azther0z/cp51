import { BrowserRouter, Route, Routes } from 'react-router-dom'
import { ToastContainer } from 'react-toastify'
import 'react-toastify/dist/ReactToastify.css'
import './App.css'
import Header from './components/Header.jsx'
import Home from './pages/Home.jsx'
import Login from './pages/Login.jsx'
import Register from './pages/Register.jsx'

function App() {
  return (
    <BrowserRouter>
      <div className="container">
        <Header />
        <main className="page-content">
          <Routes>
            <Route path="/" element={<Home />} />
            <Route path="/login" element={<Login />} />
            <Route path="/register" element={<Register />} />
            <Route
              path="/new-ticket"
              element={<ComingSoon title="Create a new appointment" />}
            />
            <Route
              path="/tickets"
              element={<ComingSoon title="My appointments" />}
            />
            <Route path="*" element={<ComingSoon title="Page not found" />} />
          </Routes>
        </main>
      </div>
      <ToastContainer position="top-right" autoClose={3500} />
    </BrowserRouter>
  )
}

function ComingSoon({ title }: { title: string }) {
  return (
    <section className="heading">
      <h1>{title}</h1>
      <p>Appointment management will be available in a future step.</p>
    </section>
  )
}

export default App

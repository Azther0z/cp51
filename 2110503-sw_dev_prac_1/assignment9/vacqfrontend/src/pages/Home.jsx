import { Link } from 'react-router-dom'
import { FaQuestionCircle, FaTicketAlt } from 'react-icons/fa'

function Home() {
  return (
    <>
      <section className='heading'>
        <h1>Vac Q: A Vaccine Booking System</h1>
        <p>Please choose from an option below</p>
      </section>
      <section className='home-actions' aria-label='Appointment options'>
        <Link to='/new-ticket' className='btn btn-reverse btn-block'>
          <FaQuestionCircle aria-hidden='true' />
          Create New Appointment
        </Link>
        <Link to='/tickets' className='btn btn-block'>
          <FaTicketAlt aria-hidden='true' />
          View My Appointments
        </Link>
      </section>
    </>
  )
}

export default Home;

const firstNumber = Number(document.getElementById('firstNum').textContent)
const secondNumber = Number(document.getElementById('secondNum').textContent)

document.getElementById('sumButton').addEventListener('click', () => {
  const total = firstNumber + secondNumber
  document.getElementById('answer').textContent =
    `${firstNumber} + ${secondNumber} equals ${total}`
})

if (new URLSearchParams(window.location.search).has('calculateSum')) {
  document.getElementById('sumButton').click()
}

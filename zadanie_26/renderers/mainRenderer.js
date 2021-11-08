const submitBtn = document.querySelector(".submit-btn")
const clearBtn = document.querySelector(".clear-btn")
const inputField = document.querySelector(".calculation-area")

function calc(expr){
    try {
        let result = eval(expr)
        inputField.value = result
        }
        catch(error){
            inputField.value = "Введите выражение корректно"
        }
}

inputField.addEventListener("keypress", (event) => {
    if(event.keyCode==13){ //enter
        calc(inputField.value)
    }
})

submitBtn.addEventListener("click", () => {
    calc(inputField.value)
})

clearBtn.addEventListener("click", () => {
    inputField.value = ""
})
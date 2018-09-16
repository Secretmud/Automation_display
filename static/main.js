function update_status(testvalue) {
    var test = document.getElementsByClassName('status');
    console.log(test);
    test.innerHTML = testvalue;
}
window.onDOMload = function() {
    setInterval(update_status, 1000)
}

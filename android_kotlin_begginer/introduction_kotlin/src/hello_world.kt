fun sum (a: Int = 3, b: Int): Int {
    println("Summary = ${a + b}")
    return a + b
}

fun sumad (a: Int = 3, b: Int = 9): Int {
    println("Summary = ${a + b}")
    return a + b
}

fun main(args: Array<String>) {
    print("Enter your name: ")
    println("Hello ${readLine()}!")
    val s: String = "8"
    print("Enter some num: ")
    val result = 7 + s.toInt() + (readLine()!!.toIntOrNull() ?: 0)
    println("result = ${result}")

    sum(1,1)
//    sum(1)  Error no value for b
    sum(b = 1)

    sumad()
    sumad(2)
    sumad(b = 3)
    sumad(b = 1, a = 4)

    println (5/2)

return
}
import kotlin.text.Typography.less

fun test_when(): Unit {
    var x: Int
    var counter = 0
    while (counter < 20) {
        x = (0..100).random()
        when (x) {
            0 -> println("x is zero!")
            2 -> println("x is 2")
            10, 100 -> println("x is 10 or 100")
            in 1..9 -> println("1 <= x <= 9")
            else -> println("Miss ${x}")
        }
        counter++
    }
}

fun char_to_num (str : String) {
    var digit: Int
    when (str) {
        "one" -> digit = 1
        "two" -> digit = 2
        else -> digit = 0
    }
    println ("str = $digit")
}

fun getYearEra(year: Int): String{
    when {
        year <= 1969 -> return "before"
        year == 1970 -> return "equals"
        year in 1971..2000 -> return "after (XX century)"
        year in 2000..2099 -> return "after (XXI century)"
        else -> return "distant future"
    }
}

fun countOfZero(str: String) {
    var count: Int = 0
    for (ch in str) {
        if (ch == '0')
            count ++
    }
    println ("In string $str finded $count zeroes")
}

fun calculateEvenDigits(input:String): Int{
    var result: Int = 0
    for (ch in input) {
        if (ch.isDigit() && ch.toString().toInt() % 2 == 0) {
            result += ch.toString().toInt()
        }
    }
    return result
}

fun main(args: Array<String>) {
    test_when()
    char_to_num("one")
    char_to_num("ten")
    print("Enter string to find zeroes: ")
    countOfZero(readLine() ?: "")
    println(calculateEvenDigits("660308340"))
}
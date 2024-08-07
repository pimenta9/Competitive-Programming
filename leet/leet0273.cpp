// ACCEPTED!

string numberToWords(int num)
{
    string tag[] = 
    {
        "",
        "One",
        "Two",
        "Three",
        "Four",
        "Five",
        "Six",
        "Seven",
        "Eight",
        "Nine",
        "Ten",
        "Eleven",
        "Twelve",
        "Thirteen",
        "Fourteen",
        "Fifteen",
        "Sixteen",
        "Seventeen",
        "Eighteen",
        "Nineteen",
        "Twenty",
        "Thirty", // 21
        "Forty",
        "Fifty",
        "Sixty",
        "Seventy",
        "Eighty",
        "Ninety",
    };

    string answer;

    if (num == 0)
    {
        answer = "Zero";
    }
    else if (num < 20)
    {
        answer = tag[num];
    }
    else if (num < 100)
    {
        answer = tag[num/10 - 2 + 20];

        if (num % 10)
            answer = answer + " " + tag[num % 10];
    }
    else if (num < 1000)
    {
        answer = tag[num/100] + " Hundred";

        if (num%100)
            answer = answer + " " + numberToWords(num%100);
    }
    else if (num < 1000000)
    {
        answer = numberToWords(num/1000) + " Thousand";

        if (num%1000)
            answer = answer + " " + numberToWords(num%1000);
    }
    else if (num < 1000000000)
    {
        answer = numberToWords(num/1000000) + " Million";

        if (num%1000000)
            answer = answer + " " + numberToWords(num%1000000);
    }
    else
    {
        answer = numberToWords(num/1000000000) + " Billion";

        if (num%1000000000)
            answer = answer + " " + numberToWords(num%1000000000);
    }

    return answer;
}

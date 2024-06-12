#include <iostream> // کتابخانه‌ی استاندارد ورودی و خروجی C++ را به برنامه اضافه می‌کند
#include <array> // کتابخانه‌ی استاندارد برای استفاده از آرایه‌ها در C++ است
#include <limits> // کتابخانه‌ای برای دسترسی به مقادیر حداکثر و حداقل مجاز در C++ است

int main() { // تابع اصلی برنامه
    const int size = 10; // تعریف ثابت برای اندازه‌ی آرایه که اعداد از ۰ تا ۹ را می‌پذیرد
    std::array<int, size> counts{}; // تعریف یک آرایه برای ذخیره‌ی تعداد تکرارهای هر عدد، مقدار اولیه‌ی آن صفر است

    std::cout << "Enter numbers between 1 and 9 (Enter 0 to stop):\n"; // پیام به کاربر برای وارد کردن اعداد

    while (true) { // تکرار تا زمانی که کاربر عدد ۰ وارد نکند
        int num;
        std::cin >> num; // خواندن عدد از ورودی

        if (num < 0 || num > 9) { // بررسی اینکه آیا عدد وارد شده در محدوده صحیح است یا خیر
            std::cout << "Invalid input! Please enter numbers between 1 and 9.\n"; // پیام به کاربر برای وارد کردن عدد معتبر
            std::cin.clear(); // پاک کردن وضعیت خطا
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // رد کردن ورودی
            continue; // ادامه به ایتریشن بعدی حلقه
        }

        if (num == 0) // اگر عدد ۰ وارد شد، حلقه را خاتمه بده
            break;

        counts[num]++; // افزایش تعداد تکرار عدد وارد شده
    }

    // یافتن عدد با بیشترین و کمترین تکرار
    int maxCount = 0, minCount = counts[1]; // مقداردهی اولیه برای بیشترین و کمترین تعداد به تعداد تکرار اولین عدد
    int maxNum = 1, minNum = 1; // مقداردهی اولیه برای بیشترین و کمترین عدد به اولین عدد

    for (int i = 1; i < size; ++i) { // حلقه برای پیدا کردن بیشترین و کمترین تعداد تکرار
        if (counts[i] > maxCount) { // اگر تعداد تکرار فعلی از بیشترین تعداد تکرار بیشتر باشد
            maxCount = counts[i]; // بروزرسانی بیشترین تعداد تکرار
            maxNum = i; // بروزرسانی بیشترین عدد
        }

        if (counts[i] < minCount && counts[i] != 0) { // اگر تعداد تکرار فعلی از کمترین تعداد تکرار کمتر باشد و مقدار صفر نباشد
            minCount = counts[i]; // بروزرسانی کمترین تعداد تکرار
            minNum = i; // بروزرسانی کمترین عدد
        }
    }

    // نمایش تعداد تکرارهای هر عدد
    std::cout << "Occurrences of each number:\n";
    for (int i = 1; i < size; ++i) {
        std::cout << "Number " << i << ": " << counts[i] << " times\n";
    }

    // نمایش عدد با بیشترین تکرار
    std::cout << "Number with maximum occurrences: " << maxNum << " (occurred " << maxCount << " times)\n";

    // نمایش عدد با کمترین تکرار
    std::cout << "Number with minimum occurrences: " << minNum << " (occurred " << minCount << " times)\n";

    return 0; // بازگشت به عنوان موفقیت اجرای برنامه
}

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// تعريف نوع البايت (BYTE) بـ 8 بت
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // التأكد من أن المستخدم أدخل اسم الملف في الـ command line
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // فتح ملف الـ forensic image المسمى card.raw
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file %s.\n", argv[1]);
        return 1;
    }

    // مصفوفة (Buffer) بحجم 512 بايت لتخزين كل بلوك يتم قراءته
    BYTE buffer[512];

    // متغيرات لتتبع اسم الصورة الحالية وملف الـ pointer الخاص بها
    FILE *img = NULL;
    char filename[8];
    int image_count = 0;

    // قراءة الملف بلوك وراء بلوك (حجم البلوك 512 بايت) حتى نهاية الملف
    while (fread(buffer, 1, 512, file) == 512)
    {
        // التحقق مما إذا كان البلوك الحالي يمثل بداية صورة JPEG جديدة
        // الهيدر بيكون: 0xff 0xd8 0xff وجزء من البايت الرابع (0xe0 إلى 0xef)
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // إذا كانت هذه ليست أول صورة تم العثور عليها، أغلق الصورة السابقة أولاً
            if (img != NULL)
            {
                fclose(img);
            }

            // إنشاء اسم للصورة الجديدة بتنسيق ثلاثي الأرقام (مثل 000.jpg, 001.jpg, وهكذا)
            sprintf(filename, "%03i.jpg", image_count);

            // فتح ملف جديد للكتابة عليه
            img = fopen(filename, "w");
            if (img == NULL)
            {
                fclose(file);
                printf("Could not create %s.\n", filename);
                return 1;
            }

            image_count++;
        }

        // إذا وجدنا صورة مفتوحة بالفعل، استمر في كتابة البلوك الحالي فيها
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    // إغلاق أي ملفات ما زالت مفتوحة في الذاكرة
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(file);
    return 0;
}

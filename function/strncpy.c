#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello, World!";
    char dest[20]; // 目标数组，足够容纳源字符串

    // 使用 strncpy 复制前 5 个字符
    strncpy(dest, src, 5);
    
    // 确保 dest 字符串以空字符结束
    dest[5] = '\0'; 

    printf("Copied string: %s\n", dest); // 输出 "Hello"

    // 如果不手动添加空字符，dest 将不会是一个有效的字符串
    char dest2[20];
    strncpy(dest2, src, 20); // 超过 src 的长度
    // 在这种情况下，dest2[13] 和后面的部分是未定义的
    printf("Full copy without null termination: %s\n", dest2); // 输出 "Hello, World!"

    return 0;
}

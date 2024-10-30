#include <stdio.h>
#include <stdlib.h>

int main() {
    // 假设key数组是已知的，这里我们使用一个示例key
    char key[] = {scnu};  // 请替换为实际的key值
    int s[2560] = {0};  // 存储加密后的数据
    int r[2560] = {0};  // 存储预期的加密结果
    int i, v11 = 0, v9 = 0;

    s[2560]=35h dup(1), 0, 2Fh dup(1), 0, 2Fh dup(1), 0, 32h dup(1)
db 0, 28h dup(1), 0, 14h dup(1), 0, 27h dup(1), 0, 3Bh dup(1)
.data:00000000004031EA                 db 0, 3Dh dup(1), 0, 70h dup(1), 0, 3Ch dup(1), 0, 0Ah dup(1)
.data:00000000004032E1                 db 0, 3Dh dup(1), 0, 73h dup(1), 0, 3Ah dup(1), 0, 0Ah dup(1)
.data:00000000004033D9                 db 0, 1Fh dup(1), 0, 73h dup(1), 0, 3Dh dup(1), 0, 66h dup(1)
.data:0000000000403512                 db 0, 21h dup(1), 0, 1Ch dup(1), 0, 6Dh dup(1), 0, 28h dup(1)
.data:00000000004035E8                 db 0, 497h dup(0FFh)

    // 初始化r数组
    for (i = 0; i <= 2559; i++) {
        r[i] = -1;
    }

    // 解密过程
    int v7, v4;
    for (i = 0; i < 2560; i++) {
        if (s[i] == 0) {
            break;
        }
        v7 = s[i] - 1;
        v4 = v7++;
        if (v4 <= 0) {
            continue;
        }
        int decrypted_char = key[v9 % 4] ^ v4;
        printf("%c", decrypted_char);
        v9++;
    }

    // 检查解密结果是否正确
    for (i = 0; i <= 2559; i++) {
        if (r[i] != s[i]) {
            printf("Lose lose lose!\n");
            break;
        }
    }
    if (i == 2560) {
        printf("Win win win!\n");
    }

    return 0;
}
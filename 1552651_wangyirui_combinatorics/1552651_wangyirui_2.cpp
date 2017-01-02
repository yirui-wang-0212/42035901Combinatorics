#include<iostream>
#include<ctime>
using namespace std;

int n;
long long int cnt;
int s_f[100], sum[100];

void stackmodel() {

    sum[0] = sum[1] = 1;//0个元素、1个元素出栈顺序都是1种
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            s_f[j] = sum[j - 1] * sum[i - j];
            sum[i] += s_f[j];
        }
    }
    cnt = sum[n];
    return;
}


int main() {

    printf("\n**             售票处找零问题                **\n");
    printf("=============================================\n");
    printf("**               请选择操作                 **\n");
    printf("**              1---输入购票人数            **\n");
    printf("**              2---利用栈模型求解          **\n");
    printf("**              3---退出程序                **\n");
    printf("=============================================\n");
    int op;
    bool flag = false;

    while (true) {

        printf("\n请选择操作：");
        scanf("%d", &op);
        
        if(op == 1){

            flag = true;
            printf("有2n人排队购票，请输入n：");
            scanf("%d", &n);
        }


        else if (op == 2) {

            if(!flag){
                printf("未输入购票人数，请输入！\n");
                continue;
            }
            flag = false;

            cnt = 0;

            clock_t clockstart, clockend;
            clockstart = clock();
            stackmodel();
            clockend = clock();
            double timeused = (clockend - clockstart) / static_cast<double>(CLOCKS_PER_SEC);
            printf("n为%d时，共有%lld种方案，所用时间为%lfs\n ", n, cnt, timeused);
        }

        else if(op== 3)
            break;

        else {
            printf("输入非法数字，请重新输入！\n");
            continue;
        }
    }

    return 0;
}

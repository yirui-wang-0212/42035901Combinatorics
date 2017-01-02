#include<iostream>
#include<ctime>
using namespace std;

long long int cnt;

//bool scheme[200];//true表示50元，false表示100元
int n;//2n表示人数
int k;//剩余50张数
int done;//已购票人数
int res_100, res_50;//剩余手持/100元/50元的人数
void search(int flag) {

    if (res_50 == 1 && flag) {
        /*scheme[done] = true;*/
        ++done;
        --res_50;
        ++k;
        ++cnt;
        /*printf("\b方案%d：\b", cnt);
        for (int i = 0; i < done; ++i) {
            printf("	第%d人：", i + 1);
            scheme[i] ? printf("%d", 50) : printf("%d", 100);
        }
        for (int i = done + 1; i < 2 * b; ++i) {
            printf("	第%d人：", i);
            printf("%d", 100);
        }*/
        return;
    }

    if (!k && !flag) {
        ++done;
        --res_100;
        --k;
        return;
    }
    if (flag) {
        --res_50;
        /*scheme[done] = true;*/
        ++done;
        ++k;
    }
    else {
        --res_100;
        /*scheme[done] = false;*/
        ++done;
        --k;
    }

    if (res_50) {
        search(true);
        ++res_50;
        --done;
        --k;
    }
    if (res_100) {
        search(false);
        ++res_100;
        --done;
        ++k;
    }
    return;
}

int main() {

    printf("\n**             售票处找零问题                **\n");
    printf("=============================================\n");
    printf("**               请选择操作                 **\n");
    printf("**              1---输入购票人数            **\n");
    printf("**              2---利用搜索策略求解         **\n");
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
            res_50 = n;
            res_100 = n;
            done = 0;
            k = 0;

            clock_t clockstart, clockend;
            clockstart = clock();
            search(true);
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

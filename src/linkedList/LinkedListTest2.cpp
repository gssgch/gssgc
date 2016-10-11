#include <stdio.h>
#include <malloc.h>
#include <conio.h>
/**
 *  链表练习  网上copy 的demo
 */
//链表单元定义，链表相关变量
struct student {
    int id;
    float score;
    struct student *next;
} *head,*pthis;

//输入数据创建链表
void input() {
    struct student *tmp;
    printf("\n\n请输入学生的信息以学号为0结束:\n");
    do {
        printf("ID\t成绩\n");
        if ((tmp=(struct student *)malloc(sizeof(struct student)))==NULL) {
            printf("\n错误!不能申请所需的内存!\n");
            exit(0);
        }
        scanf("%d\t%f",&tmp->id,&tmp->score);
        tmp->next=NULL;
        if (tmp->id!=0) {
            if (head==NULL) {
                head=tmp;
                pthis=head;
            } else {
                pthis->next=tmp;
                pthis=pthis->next;
            }
        }
    } while (tmp->id!=0);
    free(tmp);
}

//搜索链表找到第一个符合条件的项目输出
void search(int id) {
    printf("\n\n查询结果\n");
    printf("ID\t成绩\n");
    printf("-------------------------------\n");
    if (head==NULL) {
        printf("\n错误!没有数据!\n");
        return;
    }
    pthis=head;
    while (pthis!=NULL) {
        if (pthis->id==id) {
            printf("%d\t%.2f\n",pthis->id,pthis->score);
            return;
        } else {
            pthis=pthis->next;
        }
    }
    printf("\n没有找到!\n");
}

//列表输出链表中的所有项
void list() {
    printf("\n\n数据列表\n");
    printf("ID\t成绩\n");
    printf("-------------------------------\n");
    if (head==NULL) {
        printf("错误,没有数据!\n");
        return;
    }
    pthis=head;
    while (pthis!=NULL) {
        printf("%d\t%.2f\n",pthis->id,pthis->score);
        pthis=pthis->next;
    }
}

//插入数据
void insert() {
    int i,p;
    struct student *tmp;
    if (head==NULL) {
        printf("\n\n数据不存在，无法插入!\n");
        return;
    }
    printf("\n请输入插入点:\n");
    scanf("%d",&p);
    if (p<0) {
        printf("输入不合法!");
        return;
    }
    printf("\n\n请输入学生的信息:\nID\t成绩\n");
    if ((tmp=(struct student *)malloc(sizeof(struct student)))==NULL) {
        printf("\n错误!不能申请所需的内存!\n");
        exit(0);
    }
    scanf("%d\t%f",&tmp->id,&tmp->score);
    tmp->next=NULL;
    if (tmp->id!=0) {
        pthis=head;
        if (p==0) {
            tmp->next=head;
            head=tmp;
        } else {
            for (i=0; i<p-1; i++) {
                if (pthis->next->next==NULL) {
                    printf("\n找不到插入点，您输入的数据太大!\n");
                    return;
                }
                pthis=pthis->next;
            }
            tmp->next=pthis->next;
            pthis->next=tmp;
        }
    } else {
        printf("\n数据无效!\n");
        free(tmp);
    }
}

//追加数据
void append() {
    struct student *tmp;
    printf("\n\n请输入学生的信息:\nID\t成绩\n");
    if ((tmp=(struct student *)malloc(sizeof(struct student)))==NULL) {
        printf("\n错误!不能申请所需的内存!\n");
        exit(0);
    }
    scanf("%d\t%f",&tmp->id,&tmp->score);
    tmp->next=NULL;
    if (tmp->id!=0) {
        if (head==NULL) {
            head=tmp;
        } else {
            pthis=head;
            while (pthis->next!=NULL) {
                pthis=pthis->next;
            }
            pthis->next=tmp;
        }
    } else {
        free(tmp);
        printf("\n数据无效!\n");
    }
}

//删除数据
void del() {
    int p,i;
    struct student *tmp;
    if (head==NULL) {
        printf("\n\n没有数据，无法删除!\n");
        return;
    }
    printf("\n\n请输入要删除的记录号:\n");
    scanf("%d",&p);
    if (p<0) {
        printf("\n输入不合法!\n");
        return;
    }
    if (p==0) {
        pthis=head;
        head=pthis->next;
        free(pthis);
        pthis=head;
    } else {
        pthis=head;
        for (i=0; i<p-1; i++) {
            pthis=pthis->next;
            if (pthis->next==NULL) {
                printf("\n\n指定记录不存在，无法删除!\n");
                return;
            }
        }
        tmp=pthis->next;
        pthis->next=pthis->next->next;
        free(tmp);
    }
}

//程序主函数
int main() {
    char command=0;
    int id=0;

//主循环
    do {
        printf("\n\n\t菜单2\n");
        printf("-------------------------------\n");
        printf("\ta,输入数据\n");
        printf("\tb,查询记录\n");
        printf("\tc,数据列表\n");
        printf("\td,追加记录\n");
        printf("\te,插入记录\n");
        printf("\tf,删除记录\n");
        printf("\tg,退出系统\n");
        printf("-------------------------------\n");
        printf("\t请选择:");
        command=getch();

//命令处理
        switch (command) {
            case 'a':
                if (head==NULL) {
                    input();
                    break;
                } else {
                    printf("\n\n数据已经存在！\n");
                    break;
                }
            case 'b':
                printf("\n\n要查询的ID:");
                scanf("%d",&id);
                search(id);
                break;
            case 'c':
                list();
                break;
            case 'd':
                append();
                break;
            case 'e':
                insert();
                break;
            case 'f':
                del();
                break;
        }
    } while (command!='g');
}
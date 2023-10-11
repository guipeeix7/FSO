#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree
{
    struct BinaryTree *right;
    struct BinaryTree *left;
    int value;
} BinaryTree;

// Init function makes any sense  ?? 'o.... NO
BinaryTree *init()
{
    BinaryTree *root = (BinaryTree *)malloc(sizeof(BinaryTree));
    root->right = NULL;
    root->left = NULL;
    root->value = 0;
    return root;
}

BinaryTree *insert(int value)
{
    BinaryTree *newNode = (BinaryTree *)malloc(sizeof(BinaryTree));
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->value = value;
    return newNode;
}

BinaryTree *searchAndInsert(BinaryTree *node, int value)
{
    if (node == NULL)
        return insert(value);
    else if (value > node->value)
        node->right = searchAndInsert(node->right, value);
    else if (value < node->value)
        node->left = searchAndInsert(node->left, value);
    
    return node;
}

BinaryTree *search(BinaryTree *node, int value)
{
    if (node == NULL)
        return NULL;

    else if (node->value == value)
    {
        return node;
    }
    else if (node->value < value)
        search(node->right, value);
    else if (node->value > value)
        search(node->left, value);
}

BinaryTree *showBinaryTree(BinaryTree *node)
{
    if (node->left != NULL)
        showBinaryTree(node->left);
    printf("%d\n", node->value);
    if (node->right != NULL)
        showBinaryTree(node->right);
}

int isNotEmpty(BinaryTree *node)
{
    return (node != NULL) ? 1 : 0;
}

BinaryTree *deleteNode(BinaryTree *node, int value)
{
    BinaryTree *finding = search(node, 99);
    if (finding != NULL)
    {
        free(finding);
    }
    else
    {
        printf("This node isn't exists");
    }
    return finding;
    // This will be a lot more complex my brother
}

// int main(){
//     BinaryTree *root = NULL;
//     root = searchAndInsert(root , 321);
//     // searchAndInsert(root , 949);
//     // searchAndInsert(root , 524);
//     // searchAndInsert(root , 6);
//     // searchAndInsert(root , 100);
//     // searchAndInsert(root , 838);

//     // showBinaryTree(root);

//     // deleteNode(root,15);
//     // BinaryTree *finding = search(root, 99);:

//     showBinaryTree(root);

//     printf("\n");

// }

int calcDivisors(long int num)
{
    // i representa o divisor,
    long int i = 2;
    int numberOfEl = 0;

    if (!(num % 2 != 0 && num % 3 != 0 && num % 5 != 0 && num % 7 != 0))
    {
        return 0;
    }
    long int numSqrt = (long int)sqrt(num);

    while (i < numSqrt)
    {
        if (i > numSqrt)
            return 0;
        if (num % i == 0)
        {
            numberOfEl++;
            if (numberOfEl > 10)
            {
                return 1;
            }
        }
        i++;
    }

    return 0;
}

typedef struct threadParams
{
    long int n;
    int tid;
    long int result;
} threadParams;

int main()
{
    // long int maxNum = 10000000000;
    long int maxNum = 10000000000;

    BinaryTree *root = NULL; 
    root = searchAndInsert(root , 508079); 
    long int i = 508079;

    // while (maxNum--)
    // {
        // i = (maxNum > 508079) ? maxNum + 1 : 508079;
        for (; i < 10000000000; i++)
        {
            int a = calcDivisors(i);
            if (a == 1)
            {
                // printf("%d\n", i);
                searchAndInsert(root , i); 

                // return 0;
            }
        }
    // }
    showBinaryTree(root);

    // long int myInput = 0;
    // int inputSize = 0;
    // scanf("%d", &inputSize);

    // pthread_t t1;

    // pthread_create(&t1, NULL, printDivisors, NULL);

    // while (inputSize--)
    // {
    //     scanf("%ld", &myInput);
    //     printDivisors(myInput);
    // }
    // return 0;
}

// typedef struct parametro_thread
// {
//     int n;
//     int tid;
//     int result;
// } parametro_thread;

// typedef struct seedVector{
//     int begin;
//     int middle;
//     int end;
//     DLL *v;
//     int vSize;
//     int semente;
// }seedVector;

// int main(void)
// {

//     long int myInput = 0;
//     int inputSize = 0;
//     scanf("%d", &inputSize);
//     while (inputSize--)
//     {
//         // scanf("%ld", &myInput);
//         // printDivisors(myInput);

//         struct parametro_thread PARAMETRO_A.n = n;
//         cria_thread(calcule_sequaseprimo_maluco(PARAMETRO_A))

//             if (leia(n) == EOF) break;
//         struct parametro_thread PARAMETRO_B.n = n;
//         cria_thread(calcule_sequaseprimo_maluco(PARAMETRO_B))

//             espera_thread1();
//         espera_thread2();
//         imprime(PARAMETRO_A.result);
//         imprime(PARAMETRO_B.result);

//     }

// }

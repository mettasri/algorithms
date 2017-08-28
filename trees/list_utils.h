/*****************************************************************/
/*                         LL utilities                        */
/*****************************************************************/
extern "C"
{
typedef struct List
{
  int         data;
  struct List *pNext;
  struct Tree *pPrev;
} ListNode;

ListNode *createListNode(int data);
void displayList(ListNode *pHead);
void insertInList(ListNode** pHead, ListNode* pNode);
void insertLastInList(ListNode** pHead, ListNode* pNode);
void deleteFromList(ListNode** pHead, int data);
/*****************************************************************/
/*                         Tree utilities                        */
/*****************************************************************/
typedef struct Tree
{
  int         data;
  char        str[12];
  char        isRightThreaded;
  struct Tree *pLeft;
  struct Tree *pRight;
  struct Tree *pNext;
} TreeNode;

TreeNode *createNode(int data);
void displayTreeCharData(TreeNode *pBase, int spaces);
void displayTree(TreeNode *pBase, int spaces);
void displayLeftRightList(TreeNode *pBase);
void displayLeftRightCirList(TreeNode *pBase);
int max(int x, int y);
void insertNodeIntoTree(TreeNode** pBase, TreeNode* pNode);
int hasBothChild(TreeNode* pBase);

/*****************************************************************/
/*                         Stack utilities                       */
/*****************************************************************/
typedef struct Stack
{
  TreeNode     *pTNode;
  struct Stack *pNext;
} StackNode;

int isStackEmpty(StackNode **pSTop);
void push(StackNode **pSTop, TreeNode *pTNode);
TreeNode *pop(StackNode **pSTop);
void stackTraverse(StackNode **pSTop);
TreeNode *topOfStack(StackNode **pSTop);

/*****************************************************************/
/*                         Queue utilities                       */
/*****************************************************************/
typedef struct Queue
{
  int front;
  int rear;
  int size;
  TreeNode **pQTree;
} QueueNode;

QueueNode* createQueue(int size);
int isQueueEmpty(QueueNode *pQBase);
int isQueueFull(QueueNode *pQBase);
int hasOnlyOneItemInQueue(QueueNode *pQBase);
int noOfEleInQueue(QueueNode *pQBase);
void enQueue(QueueNode *pQBase, TreeNode *pTNode);
TreeNode* deQueue(QueueNode *pQBase);
TreeNode* getFront(QueueNode *pQBase);
void displayQueue(QueueNode *pQBase);
}

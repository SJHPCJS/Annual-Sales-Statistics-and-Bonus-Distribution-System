#ifndef STAFF_DATA_STRUCTURE
#define STAFF_DATA_STRUCTURE

typedef struct staff {
    char id[5];
    char name[16];
    double saleOf1stQuarter;
    double saleOf2ndQuarter;
    double saleOf3thQuarter;
    double saleOf4thQuarter;
    double sumOfSales;
    double bonus;
} Staff, *pStaff;

typedef struct staffNode StaffNode, *pStaffNode;
struct staffNode {
    int color;
    // 0: black; 1: red
    pStaff Staff;
    pStaffNode parent;
    pStaffNode leftChild;
    pStaffNode rightChild;
};

typedef struct staffTree {
    pStaffNode root;
    int size;
} StaffTree, *pStaffTree;

pStaffNode createStaffNode(pStaff staff, int color);
void rbTreeAdjust(pStaffTree tree, pStaffNode node);
void rbTreeInsert(pStaffTree tree, pStaff staff);
void destroyTree(pStaffNode node);
#endif
#include "../include/main.h"

int HasPermission(DirectoryNode* dirNode, char pms)
{
    if(usrList->current->UID == 0)
        return 0;

    if(usrList->current->UID == dirNode->UID){
        if(pms == 'r'){
            if(dirNode->permission[0] == 0)
                return -1;
            else
                return 0;
        }
        if(pms == 'w'){
            if(dirNode->permission[1] == 0)
                return -1;
            else
                return 0;
        }
        if(pms == 'x'){
            if(dirNode->permission[2] == 0)
                return -1;
            else
                return 0;
        }
    }
    else if(usrList->current->GID == dirNode->GID){
        if(pms == 'r'){
            if(dirNode->permission[3] == 0)
                return -1;
            else
                return 0;
        }
        if(pms == 'w'){
            if(dirNode->permission[4] == 0)
                return -1;
            else
                return 0;
        }
        if(pms == 'x'){
            if(dirNode->permission[5] == 0)
                return -1;
            else
                return 0;
        }
    }
    else{
        if(pms == 'r'){
            if(dirNode->permission[6] == 0)
                return -1;
            else
                return 0;
        }
        if(pms == 'w'){
            if(dirNode->permission[7] == 0)
                return -1;
            else
                return 0;
        }
        if(pms == 'x'){
            if(dirNode->permission[8] == 0)
                return -1;
            else
                return 0;
        }
    }
    return -1;
}

int Atoi_permission(DirectoryNode* dirNode)
{
    char buffer[4];
    int tmp;

    for(int i=0;i<9;i++)
        dirNode->permission[i] = 0;

    sprintf(buffer, "%d", dirNode->mode);

    for(int i=0;i<3;i++){
        tmp = buffer[i] - '0';
        for (int j = 2 ; j >= 0 ; j--)
        {
            dirNode->permission[3*i+j] = tmp%2;
            tmp /= 2;
        }
    }

    return 0;
}

void PrintPermission(DirectoryNode* dirNode)
{
    char rwx[4] = "rwx";

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(dirNode->permission[3*i+j] == 1)
                printf("%c", rwx[j]);
            else
                printf("-");
        }
    }

}
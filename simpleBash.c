/*#include <string.h>
#include <stdio.h>
#include "sfsHeader.h"


void ls();

void mkdir();

void cd();

void lsrec();

int getFreeInodeNumber(int *inode_bitmap);

struct super_block sb;
struct inode_st root;

int main(){
	
char command [32];
	while(1){
		printf("> ");
		scanf("%s", command);
		
		if(strcmp(command, "ls") == 0){
			ls();
		}
		if(strcmp(command, "mkdir") == 0){
			mkdir();
		}
		else if(strcmp(command, "lspfs") == 0){
			printf("you typed lspfs");
		}
		
	}
	
	return 0;
}
void ls_cur(int curDirInodeNum);
void get_inode_struct(FILE *f, struct inode_st *inode , int inode_num);


void ls (){
	int i;
	struct dir_ent entry;

	FILE *sfs = fopen("sfs.bin", "r");
	//jump
	
	//it goes to whatever current inode number is
	// -if its 5 then  its goes and opens the inode number 5 directory 
	//lste  de bak
	fseek(sfs, sizeof(sb)+curDirInodeNum*sizeof(struct inode_st), SEEK_SET);
	fread(&root, sizeof(struct inode_st), 1, sfs);
	printf("size: %d\n", root.size);

	int numOfEntries = root.size/sizeof(struct dir_ent); 
	fseek(sfs, sizeof(sb)+32*sizeof(struct inode_st), SEEK_SET);
	for(i = 0; i < numOfEntries; i++){
		fread(&entry, sizeof(struct dir_ent), 1, sfs);
		printf( "%s\n", entry.name);
	}

}
//directory entries are stored in datablocks which belong to a directory
//human and computer
//to get a directory entry, we need to know two things -> 1) which datablock index its in -in 16 blocks, 
//2) once i find the data block where in the data block the directory entry is 
//when we call this methods, we pass the address of dirent
//get directory entry -datablockindices -give me datablockindex and i will return dirent


void getDirEntry(struct dir_ent*de, int dataBlockIndex, int direntIndex ){
	//..
	//strcpy(de.name
	//de.inode_no =  ...
};


// we wrote these codes just copy and paste it
//give me get inodenumber and return inode structure for you
/*void inode_st getInodeStructure(struct inode_st*is, int iNodeNumber){
	
};


//if i wnat to get free inodenumber i need to get inodebitmap
//1 - we just check the bits 
//pass only address of one integer -inode bitmap is a integer in the superblock
int getFreeInodeNumber(int *inode_bitmap){
	return 0;
}
//2 -array
int getFreeDataBlockNumber(*int data_bitmap){
	return 0;
}
//modify superblock -it takes bitnumber -0,1,25,26..(if its a inodebitmap)- and set number
void setBit (int *inode_bitmap int *data_bitmap) {
	
} */

/* int getFreeInodeNumber(int *inode_bitmap){
	int i;
	struct dir_ent entry;
    FILE *sfs = fopen("sfs.bin", "r");
	fseek(sfs, sizeof(struct super_block)+sb.inode_bitmap*sizeof(struct inode_st), SEEK_SET);
	fread(&entry, sizeof(struct dir_ent), 1, sfs);
	
	for(i = 0; i <NUMOFINODES; i++){
		if(entry.inode_no != 0)
		{
		entry.inode_no++;
		}
		
		else {
		curDirInodeNum =  entry.inode_no + 1;
		}	
	}
		
	return curDirInodeNum;
} 

void mkdir() {
	char fileName[32];
	scanf("%s", fileName);
	
	int cur = getFreeInodeNumber(sb.inode_bitmap);
	
	int i ;
	struct inode_st newDirectory;
	struct dir_ent newEntry;
	//Created an inode structure for new directory
	
	newDirectory.type = DIRECTORY;
	newDirectory.size = DIRENTRYSIZE;

//for computer
	
	struct dir_ent dot;
	strcpy(dot.name,".");
	dot.inode_no = curDirInodeNum;
	struct dir_ent dotdot;
	strcpy(dotdot.name,"..");
	dotdot.inode_no = curDirInodeNum;
	

	sb.inode_bitmap = sb.inode_bitmap + 1;
	sb.data_bitmap[0] = sb.data_bitmap[0] + 1;

	
	for(i = 0; i < 10; i++){
		newDirectory.data_block_indices[i] = 1;
	}
	
	
	
//modified the superblock
	
	
	FILE *sfs = fopen("sfs.bin", "w+");
	
//write the inode structure to it's location	

	fseek(sfs, sizeof(struct super_block)+sb.inode_bitmap*sizeof(struct inode_st), SEEK_SET);
	fwrite(&newDirectory, sizeof(newDirectory), 1, sfs);
	
	fwrite(&dot, sizeof(dot), 1, sfs);
	fwrite(&dotdot, sizeof(dotdot), 1, sfs);
	
	strcpy(newEntry.name,fileName);
	newEntry.inode_no = 0;
	
	fseek(sfs, sizeof(struct super_block)+(32*sizeof(struct inode_st))+(2*sizeof(struct dir_ent)), SEEK_SET);
	fwrite(&newEntry, sizeof(struct dir_ent), 1, sfs);
	
	root.size += sizeof(struct dir_ent);
	
	fseek(sfs, 0, SEEK_SET);
	fwrite(&sb, sizeof(sb), 1, sfs);
	fwrite(&root, sizeof(root), 1, sfs);

	fclose(sfs);
	
}
 */

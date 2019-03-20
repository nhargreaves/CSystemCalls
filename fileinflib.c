/*
 * Replace the following string of 0s with your student number
 * 150405531
 */
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>

#include "fileinflib.h"

/* is_user_exec helper function forward declaration */
bool is_user_exec(mode_t mode, uid_t owner_uid, gid_t owner_gid);

/***************************************************************************/
/***** FILEINFLIB.H IMPLEMENTATIONS ****************************************/
/***************************************************************************/
 
/* see mode2str specification comments in fileinflib.h */
char *mode2str(mode_t mode, uid_t owner_uid, gid_t owner_gid) { 

  //TEMP CODE
  char *mode2str(mode_t mode, uid_t owner_uid, gid_t owner_gid) { 
    char *mode_s = (char *) calloc(MODE_S_LEN, sizeof(char));
    
    if (mode_s) {
        mode_s[0] = 'o';
        for (int i = 1; i < MODE_S_LEN - 1; i++)
            mode_s[i] = '-';

        mode_s[MODE_S_LEN - 1] = '\0';
    }
    
    return mode_s;
}
}

/* see getfileinf specification comments in fileinflib.h */
fileinf *getfileinf(char *path) {
	
 if (path.length>MAXPATHLEN) {//return invalid error if length is too long
	 errno = EINVAL;
 }
 fileinf* newFile = malloc(sizeof(listitem)); //allocate space for new instance of fileinf

 newFile ntype = path->type; //set values for new instance of fileinf
 newFile mode_s = path->mode_s;
 newFile size = path->size;
 
    return newFile;
}

/* see delfileinf specification comments in fileinflib.h */
void delfileinf(fileinf *fi) { 
	if (fi!=NULL) { 
        if (fi->!=NULL) {
			free(fi->mode_s);
		}
		free(fi->dirname);
		free(fi->basename);
		free(fi);
    }
}

/***************************************************************************/
/***** HELPER FUNCTIONS ****************************************************/
/***************************************************************************/

/* 
 * is_user_exec helper function to test user execute permission for given 
 * file mode and file owner uid and file owner gid.
 * Uses getuid() to get the uid of the calling process and getgid() to get the 
 * gid of the calling process.
 * This function is not part of the filecmdrlib interface.
 */ 
bool is_user_exec(mode_t mode, uid_t owner_uid, gid_t owner_gid) {
    if (owner_uid == getuid())
        return mode & S_IXUSR;
    
    if (owner_gid == getgid())
        return mode & S_IXGRP;
        
    return mode & S_IXOTH;
}

/***************************************************************************/

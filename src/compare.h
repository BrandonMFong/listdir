/**
 * author: brando
 * date: 4/14/25
 */

#ifndef LISTDIR_COMPARE_H
#define LISTDIR_COMPARE_H

#include <limits.h>
#include <sys/stat.h>
#include <dirent.h>

#ifdef LINUX
#include <linux/limits.h>
#endif

// holds the current path we are currently working on
// 
// if we are doing any recursion, I will need to use a stack
extern char scanDirCallbackCWD[PATH_MAX];

int CompareScanDirTimeModifiedAscending(const struct dirent ** a, const struct dirent ** b);
int CompareScanDirTimeModifiedDescending(const struct dirent ** a, const struct dirent ** b);

int CompareScanDirSizeAscending(const struct dirent ** a, const struct dirent ** b);
int CompareScanDirSizeDescending(const struct dirent ** a, const struct dirent ** b);


#endif // LISTDIR_COMPARE_H


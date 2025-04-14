/**
 * author: brando
 * date: 4/14/25
 */

#include "compare.h"
#include <stdio.h>
#include <time.h>

char scanDirCallbackCWD[PATH_MAX];

/**
 * sortDirection: see Arguments::sortDirection
 */
int CompareScanDirTimeModified(unsigned char sortDirection, const struct dirent ** a, const struct dirent ** b) {
	if (!a || !b) return 0;

	struct stat sta, stb;
	char patha[PATH_MAX], pathb[PATH_MAX];

	snprintf(patha, PATH_MAX, "%s/%s", scanDirCallbackCWD, (*a)->d_name);
	snprintf(pathb, PATH_MAX, "%s/%s", scanDirCallbackCWD, (*b)->d_name);

	stat(patha, &sta);
	stat(pathb, &stb);

	double diff = difftime(sta.st_mtime, stb.st_mtime);

	if (sortDirection == 1) {
		return (int) (diff * -1.0);
	} else {	
		return (int) diff;
	}
}

int CompareScanDirTimeModifiedAscending(const struct dirent ** a, const struct dirent ** b) {
	return CompareScanDirTimeModified(0, a, b);
}

int CompareScanDirTimeModifiedDescending(const struct dirent ** a, const struct dirent ** b) {
	return CompareScanDirTimeModified(1, a, b);
}

/**
 * sortDirection: see Arguments::sortDirection
 */
int CompareScanDirSize(unsigned char sortDirection, const struct dirent ** a, const struct dirent ** b) {
	if (!a || !b) return 0;

	struct stat sta, stb;
	char patha[PATH_MAX], pathb[PATH_MAX];

	snprintf(patha, PATH_MAX, "%s/%s", scanDirCallbackCWD, (*a)->d_name);
	snprintf(pathb, PATH_MAX, "%s/%s", scanDirCallbackCWD, (*b)->d_name);

	stat(patha, &sta);
	stat(pathb, &stb);

	if (sortDirection == 1) {
		return stb.st_size - sta.st_size;
	} else {	
		return sta.st_size - stb.st_size;
	}
}

int CompareScanDirSizeAscending(const struct dirent ** a, const struct dirent ** b) {
	return CompareScanDirSize(0, a, b);
}

int CompareScanDirSizeDescending(const struct dirent ** a, const struct dirent ** b) {
	return CompareScanDirSize(1, a, b);
}


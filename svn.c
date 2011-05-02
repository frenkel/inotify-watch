#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <subversion-1/svn_client.h>

int main(int argc, char *argv[]) {
	struct apr_array_header_t **result_revs;
	struct apr_array_header_t *paths;
	const struct svn_opt_revision_t *revision;

	apr_pool_t *mp;

	apr_initialize();
	apr_pool_create(&mp, NULL);

	paths = apr_array_make(mp, 1, sizeof(const char*));
	*(const char**)apr_array_push(paths) = argv[1];
	
	svn_client_update3(result_revs, paths, revision, svn_depth_unknown, 0, 0, 1, NULL, NULL);

	exit(EXIT_SUCCESS);
}

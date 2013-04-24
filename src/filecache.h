#ifndef fooldbfilecachehfoo
#define fooldbfilecachehfoo

/***
  This file is part of fusedav.

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
***/

#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <leveldb/c.h>
#include <glib.h>
#include "session.h"
#include "fuse.h"

#define E_FC_PDATANULL 1
#define E_FC_LDBERR 2
#define E_FC_CURLERR 3

typedef leveldb_t filecache_t;

void filecache_print_stats(void);
void filecache_init(char *cache_path, GError **gerr);
void filecache_delete(filecache_t *cache, const char *path, bool unlink, GError **gerr);
void filecache_open(char *cache_path, filecache_t *cache, const char *path, struct fuse_file_info *info,
    unsigned grace_level, bool *used_grace, GError **gerr);
ssize_t filecache_read(struct fuse_file_info *info, char *buf, size_t size, off_t offset, GError **gerr);
ssize_t filecache_write(struct fuse_file_info *info, const char *buf, size_t size, off_t offset, GError **gerr);
void filecache_close(struct fuse_file_info *info, GError **gerr);
void filecache_sync(filecache_t *cache, const char *path, struct fuse_file_info *info, bool do_put, GError **gerr);
void filecache_truncate(struct fuse_file_info *info, off_t s, GError **gerr);
int filecache_fd(struct fuse_file_info *info);
void filecache_pdata_move(filecache_t *cache, const char *old_path, const char *new_path, GError **gerr);
void filecache_cleanup(filecache_t *cache, const char *cache_path, bool first, GError **gerr);

#endif

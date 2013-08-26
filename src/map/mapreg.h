// Copyright (c) Hercules Dev Team, licensed under GNU GPL.
// See the LICENSE file
// Portions Copyright (c) Athena Dev Teams

#ifndef _MAPREG_H_
#define _MAPREG_H_

#include "../common/cbasetypes.h"
#include "../common/db.h"

struct mapreg_save {
	int64 uid;
	union {
		int i;
		char *str;
	} u;
	bool save;
};

struct mapreg_interface {
	DBMap *db; // int64 var_id -> int value
	DBMap *str_db; // int64 var_id -> char* value
	struct eri *ers; //[Ind/Hercules]
	char table[32];
	bool i_dirty;
	bool str_dirty;
	/* */
	void (*init) (void);
	void (*final) (void);
	/* */
	int (*readreg) (int64 uid);
	char* (*readregstr) (int64 uid);
	bool (*setreg) (int64 uid, int val);
	bool (*setregstr) (int64 uid, const char *str);
	void (*load) (void);
	void (*save) (void);
	int (*save_timer) (int tid, unsigned int tick, int id, intptr_t data);
	void (*reload) (void);
	bool (*config_read) (const char *w1, const char *w2);
};

struct mapreg_interface *mapreg;

void mapreg_defaults(void);

#endif /* _MAPREG_H_ */

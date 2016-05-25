local proto = {
	CG_ASK_LOGIN = 
	{
		{"account",1,"string"},
		{"authkey",1,"string"},
	},

	GC_ZZ_HUMAN_INFO =
	{
		{"id",1,"int"},
		{"name",1,"string"},
		{"cid",1,"int"},
	},

	GC_MOVE =
	{
		{"account",1,"string"},
		{"obj_id", 1, "int"},
		{"x", 1, "int"},
		{"y", 1, "int"},
		{"points", 128, "int"},
		{"testdouble", 6, "double"},
	}
}

return proto
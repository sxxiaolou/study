local proto = {
	CG_ASK_LOGIN = 
	{
		{"account",1,"string"},
		{"authkey",1,"string"},
		{"testint",4,"int"},
	},

	GC_MOVE =
	{
		{"account",1,"string"},
		{"obj_id", 1, "int"},
		{"x", 1, "int"},
		{"y", 1, "int"},
		{"points", 128, "int"},
	}
}

return proto
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

	GC_ENTER_SCENE =
	{
		{"scene_id",1,"int"},
		{"x",1,"int"},
		{"y",1,"int"},
		{"mapType",1,"int"},
		{"iid",1,"int"},
	},

	GC_VIEW_STATUS_CHANGE = 
	{
		{"iid",               1,          "int"},         --实体ID
		{"status",              1,          "int"},         --状态
		{"viewinfo",            1,          "ViewInfo"},      --可视数据
	},

	ViewInfo = {
		{"body",                        1,                      "int"},
		{"bone",                        1,                      "int"},
	}
}

return proto
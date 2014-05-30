class var {
	void *value;
	char type;
	var(int);
	var(const char *);
	~var();
};

var::var(int x)
{
	value = new int;
	*(int *) value=x;
}

var::var(const char *s)
{
	value= new char[strlen(s)+1];
	strcpy((char *)value,s);
}

/* in file getc.c */
extern	syscall	getc(did32);

/* in file putc.c */
extern	syscall	putc(did32, char);

/* in file start.S */
extern	int32	inb(int32);
extern	int32	inw(int32);
extern	int32	inl(int32);
extern	int32	outb(int32, int32);
extern	int32	outw(int32, int32);
extern	int32	outl(int32, int32);
extern	int32	outsw(int32, int32, int32);
extern	int32	insw(int32, int32 ,int32);

/* in file ttygetc.c */
extern	devcall	ttygetc(struct dentry *);

/* in file ttyinit.c */
extern	devcall	ttyinit();
/* in file ttykickout.c */
extern	void	ttykickout(struct uart_csreg *);

/* in file ttyputc.c */
extern	devcall	ttyputc(struct dentry *, char);


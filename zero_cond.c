	if (tr->type == 's' && tr->zero)
		tr->zero = tr->width;
	else if (tr->minus && tr->zero)
	{
		tr->minus = tr->zero;
		tr->zero = 0;
	}
	// ERROR: precision *is* zero; must print width as blank space!
	// could tr->len = 0 be a good test?
	if (!(tr->zero || tr->minus) && tr->len > 0)
		tr->width = 0;

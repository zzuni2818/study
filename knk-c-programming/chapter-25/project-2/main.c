#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define PRINT_S(X) printf(#X " = \"%s\"\n", X)
#define PRINT_I(X) printf(#X " = %d\n", X)
#define PRINT_D(X) printf(#X " = %d\n", *X)

void print_lconv(struct lconv *lc);

int main()
{
	//must be installed language-pack-fi
	const char *locale = "fi_FI.utf8";

	char *str_locale = setlocale(LC_ALL, locale);
	if(str_locale == NULL) {
		fprintf(stderr, "Failed to set locale: %s\n", locale);
		exit(EXIT_FAILURE);
	}

	printf("%s\n", str_locale);
	print_lconv(localeconv());

	return 0;
}
void print_lconv(struct lconv *lc)
{
	printf("================== lconv ==================\n");
	PRINT_S(lc->decimal_point);
	PRINT_S(lc->thousands_sep);
	PRINT_D(lc->grouping);
	PRINT_S(lc->mon_decimal_point);
	PRINT_S(lc->thousands_sep);
	PRINT_D(lc->mon_grouping);
	PRINT_S(lc->positive_sign);
	PRINT_S(lc->negative_sign);
	PRINT_S(lc->currency_symbol);
	PRINT_I(lc->frac_digits);
	PRINT_I(lc->p_cs_precedes);
	PRINT_I(lc->n_cs_precedes);
	PRINT_I(lc->p_sep_by_space);
	PRINT_I(lc->n_sep_by_space);
	PRINT_I(lc->p_sign_posn);
	PRINT_I(lc->n_sign_posn);
	PRINT_S(lc->int_curr_symbol);
	PRINT_I(lc->int_p_cs_precedes);
	PRINT_I(lc->int_n_cs_precedes);
	PRINT_I(lc->p_sep_by_space);
	PRINT_I(lc->n_sep_by_space);
	PRINT_I(lc->n_sign_posn);
	printf("===========================================\n");
}

//int getInt(void)
//{
//	int value, keeptrying = 1, rc;
//	char x;
//
//
//
//	do {
//
//
//		rc = scanf("%d%c", &value, &x);
//		if (rc == 0)
//		{
//			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
//			while (getchar() != '\n');
//		}
//		else if (x != '\n')
//		{
//			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
//			while (getchar() != '\n');
//		}
//
//
//		else
//			keeptrying = 0;
//	} while (keeptrying == 1);
//
//
//	return value;
//
//
//}

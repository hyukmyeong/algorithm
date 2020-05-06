<stdio.h>

int do_blending()
{
	// RGB =
  int objA = 0xA8B8C8D8;
	int objB = 0xA9334353;
	int objA_R, objA_G, objA_B;
	int objB_R, objB_G, objB_B;
	float objA_A, objB_A;

	int new_obj_R, new_obj_G, new_obj_B;
	int new_obj2_R, new_obj2_G, new_obj2_B;

	//scanf("%x", &objA);
	//fflush(stdin);
	//scanf("%x", &objB);
	
	objA_A = ((objA & 0xFF000000) >> 24) / 255.0;
	objA_R = (objA & 0x00FF0000) >> 16;
	objA_G = (objA & 0x0000FF00) >> 8;
	objA_B = (objA & 0x000000FF);

	//alpha_objB = ((objB & 0xFF000000) >> 24) / 255.0;
	objB_A = 1 - objA_A;
	//alpha_objB = BB / 255.0;
	objB_R = (objB & 0x00FF0000) >> 16;
	objB_G = (objB & 0x0000FF00) >> 8;
	objB_B = (objB & 0x000000FF);


	new_obj_R = (int)((objA_R * objA_A) + (objB_R * objB_A));
	new_obj_G = (int)((objA_G * objA_A) + (objB_G * objB_A));
	new_obj_B = (int)((objA_B * objA_A) + (objB_B * objB_A));

	new_obj2_R = (int)((objA_R - objB_R) * objA_A + objB_R);
	new_obj2_G = (int)((objA_G - objB_G) * objA_A + objB_G);
	new_obj2_B = (int)((objA_B - objB_B) * objA_A + objB_B);

	printf("%f, %f\n", objA_A, objB_A);
	printf("%d, %d, %d\n", objA_R, objA_G, objA_B);
	printf("%d, %d, %d\n", objB_R, objB_G, objB_B);
	printf("%d, %d, %d\n", new_obj_R, new_obj_G, new_obj_B);
	printf("%d, %d, %d\n", new_obj2_R, new_obj2_G, new_obj2_B);
}

int main()
{
	do_blending();
}

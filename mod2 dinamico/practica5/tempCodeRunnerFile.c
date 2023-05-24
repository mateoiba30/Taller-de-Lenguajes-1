    campo p[5035];
    fread(p, sizeof(campo), 5000, binario);
    int i;
    for (i=0; i<5000; i++){
        printf("%ld\t%d\n", p[i].dni, p[i].pos);
    }

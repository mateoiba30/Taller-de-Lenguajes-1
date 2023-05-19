    reporte = fopen("reporte_vinos.txt", "w");
    if (reporte == NULL){
        printf ("Error en reporte\n");
        return 1;
    }
    escribirArchivo(reporte, mResultados, inicio);
    fclose(reporte);
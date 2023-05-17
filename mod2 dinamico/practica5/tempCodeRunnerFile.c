        while (!feof(f)){
            fgets(palabra_act,255,f);//el archivo va a lo último
            palabra_act[strcspn(palabra_act, "\n")] = '\0'; // Eliminar el carácter de nueva línea

            //fgets lee hasta un cambio de linea
            //si quiero leer hasta cierta condicion puedo usar fscanf con un caracter de escape
            if(strcmp(palabra_act,palabra)==0){
                encontre=1;
            }
        }
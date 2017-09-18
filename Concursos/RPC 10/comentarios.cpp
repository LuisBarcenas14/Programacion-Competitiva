

/*
bool insertar(map4 &gmapa, vii &arr, int v){
    //4
    if(gmapa.find(a) == gmapa.end()){
        cout<<"No existe nodo "<<a<<endl;
        gmapa.insert(make_pair(a, gmapa3));
    }
    //3
    map3 gmapat3= gmapa[a];
    if(gmapat3.find(b) == gmapat3.end()){
        //gmapat3.insert(make_pair(b, gmapa2));
    }
    //2
    map2 gmapat2= gmapat3[b];
    if(gmapat2.find(c) == gmapat2.end()){
        gmapat2.insert(make_pair(c, gmapa1));
    }
    //1
    map<int, int> gmapat1= gmapat2[c];
    if(gmapat1.find(d) == gmapat1.end()){
        gmapat1.insert(make_pair(d, v));
        cout<<"INSERTADO v: "<<v<<" p: "<<p<<endl;
        arr.push_back(make_pair(p,1));
        return true;
    }else{
        v = gmapat1[d];
        arr[v].second++;
        cout<<"YA EXISTE v: "<<v<<" p: "<<p<<endl;
        if(arr[v].first<p)
            arr[v].first=p;
        return false;
    }
}
*/

/*
int encontrar(map4 gmapa, vii arr, int a, int b, int c, int d){
    //4
    if(gmapa.find(a) == gmapa.end()){
        cout<<"no a";
        return 0;
    }
    //3
    map3 gmapat3= gmapa[a];
    if(gmapat3.find(b) == gmapat3.end()){
        cout<<"no b";
        return 0;
    }
    //2
    map2 gmapat2= gmapat3[b];
    if(gmapat2.find(c) == gmapat2.end()){
        cout<<"no c";
        return 0;
    }
    //1
    map<int, int> gmapat1= gmapat2[c];
    if(gmapat1.find(d) == gmapat1.end()){
        cout<<"no d";
        return 0;
    }else{
        int v = gmapat1[d];
        V+=arr[v].second;
        return arr[v].first*arr[v].second;
    }
}*/


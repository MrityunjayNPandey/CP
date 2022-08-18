monitor semaphore{
    int value=0;
    condition c;
}

semaphore_increment(){
    value++;
    c.signal();
}

semaphore_decrement(){
    while(value==0){
        c.wait();
        value--;
    }
}
void AdjustDown(int* _a,int size,int root)
{
	int parent = root;
	size_t child = parent*2+1;
	//Compare com;
	while (child < size)
	{
		if((child +1 < size) && _a[child+1]<_a[child] )
		{
			++child;
		}
		if(_a[child] < _a[parent])
		{
			swap(_a[child],_a[parent]);
			parent = child;
			child = parent*2+1;
		}
		else
			break;
	}
}

void CreateAndSort(int* _a,int size)
{
	if(_a == NULL || size <= 1)
		return;

	//create
	for(int i = (size-2)/2; i>=0;--i)
		AdjustDown(_a,size,i);
	
	//sort
	for(int i = 0;i<size;++i)
	{
		swap(_a[0],_a[size-i-1]);
		AdjustDown(_a,size-i-1,0);
	}
}

//red bag :>	result not seq
//1.create small heap
//2.use new input number to replace array[0]
//3.adjustdown();

void findTopK(int *a,int size,int k)
{
	if(a==NULL || size<=0 || k<= 0 || k> size)
		return;

	//create
	for(int i = (k-2)/2; i>=0;--i)
		AdjustDown(a,k,i);

	for(int i=k;i<size;++i)
	{
		a[0]=a[i];
		AdjustDown(a,k,0);
	}

	cout<<"top K is:>"<<endl;
	for(int i=0;i<k;++i)
		cout<<a[i]<<" ";
	cout<<endl;
}

void Print(int* _a,int size)
{
	for(int i = 0; i<size;++i)
		cout<<_a[i]<<" ";
	cout<<endl;
}

void Test3()
{
	int a[11] = {10,16,18,12,11,13,15,31,14,19,19};
	//CreateAndSort(a,10);
	//Print(a,10);

	findTopK(a,11,8);
}
void vec2dTest()
{
  // Load our library into
  // the ROOT system to be
  // usable!
  gSystem->Load("../Lib/libVec2d.so");

  vec2d *v=new vec2d(2,2);
  v->Print();
  cout<<v->Length()<<endl;

        
    
  delete v;
}

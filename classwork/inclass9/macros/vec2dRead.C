void vec2dRead()
{
  // Load our library into
  // the ROOT system to be
  // usable!
  gSystem->Load("../Lib/libVec2d.so");

  TFile *f=new TFile("vec2dWriteTest.root","READ");
  f->ls();
  cout<<endl;

  vec2d *v=(vec2d*) f->Get("myFirstvec2d");
  
  v->Print();

}

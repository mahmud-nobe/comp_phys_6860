void vec2dWrite()
{
  // Load our library into
  // the ROOT system to be
  // usable!
  gSystem->Load("../Lib/libVec2d.so");

  vec2d *v=new vec2d(2,2);
  v->Print();
  cout<<v->Length()<<endl;

  TFile *f=new TFile("vec2dWriteTest.root","RECREATE");
  v->Write("myFirstvec2d");

  f->Write();
  f->Close();
    
  delete v;
}

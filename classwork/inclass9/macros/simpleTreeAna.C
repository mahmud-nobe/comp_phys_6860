void simpleTreeAna()
{
  TFile *f = new TFile("treeSimple.root","READ");
  TTree *t1 = (TTree*)f->Get("t1");
  Float_t px, py, pz;
  Int_t ev;

  t1->SetBranchAddress("px",&px);
  t1->SetBranchAddress("py",&py);
  t1->SetBranchAddress("pz",&pz);
  t1->SetBranchAddress("ev",&ev);

  // create two histograms
  TH1F *hpx   = new TH1F("hpx","px distribution",100,-3,3);
  TH2F *hpxpy = new TH2F("hpxpy","py vs px",30,-3,3,30,-3,3);

  //read all entries and fill the histograms
  Int_t nentries = (Int_t)t1->GetEntries();
  
  for (Int_t i=0; i<nentries; i++) {
    t1->GetEntry(i);
    hpx->Fill(px);
    hpxpy->Fill(px,py);
  }

  TCanvas *c1=new TCanvas("c1","",800,600);
  hpxpy->DrawCopy("colz");

  // We do not close the file. We want to keep the generated
  // histograms we open a browser and the TreeViewer
  //if (gROOT->IsBatch()) return;
  //new TBrowser ();
  //t1->StartViewer();	
}

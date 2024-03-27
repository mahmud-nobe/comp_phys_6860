#include "TCanvas.h"
#include "TROOT.h"
#include "TH3.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TArrow.h"
#include "TLatex.h"

void plot(TString fName="lorenz.root")
{
	TFile *f = new TFile(fName, "READ");
	TH3D *h3d = (TH3D*) f->Get("hlorenz3d");
	
	h3d->DrawCopy();
}

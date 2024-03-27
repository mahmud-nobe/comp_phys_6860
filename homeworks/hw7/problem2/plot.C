#include "TCanvas.h"
#include "TROOT.h"
#include "TH2.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TArrow.h"
#include "TLatex.h"

void plot(TString fName="pendulum.root")
{
	TFile *f = new TFile(fName, "READ");
	TH2D *h2d = (TH2D*) f->Get("hpendulum2d");
	
	h2d->SetTitle("Pendulum Histogram; Theta [rad]; Phi [rad]");
	h2d->DrawCopy();
}

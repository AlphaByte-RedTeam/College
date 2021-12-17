unit TransformationProject;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ExtCtrls, StdCtrls,
  ComCtrls, CheckLst;

type

  { TtranformationForm }

  TtranformationForm = class(TForm)
    btnLoad: TButton;
    checkCenter: TCheckBox;
    imgOriginal: TPaintBox;
    openDialog: TOpenDialog;
    tBarZoom: TTrackBar;
    tBarX: TTrackBar;
    tBarY: TTrackBar;
    procedure btnLoadClick(Sender: TObject);
    procedure checkCenterChange(Sender: TObject);
  private

  public

  end;

var
  tranformationForm: TtranformationForm;

implementation

{$R *.lfm}

{ TtranformationForm }

procedure TtranformationForm.btnLoadClick(Sender: TObject);
begin
end;

procedure TtranformationForm.checkCenterChange(Sender: TObject);
begin
  imgOriginal.Invalidate;
end;

end.


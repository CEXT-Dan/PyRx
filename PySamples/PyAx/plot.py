import traceback
import os
from pyrx import Ap, Ax, Db, Ge, Ed
from pypdf import PdfWriter


@Ap.Command()
def doit():
    # Keep track of generated profile paths to cleanly purge them upon completion
    silent_pc3_name = "DWG To PDF.pc3"

    try:
        axApp = Ap.Application.acadApplication()
        axDoc = axApp.activeDocument()
        custom_configs = axDoc.plotConfigurations()
        try:
            custom_config = custom_configs.item("MyTempPDFConfig")
        except Exception:
            custom_config = custom_configs.add("MyTempPDFConfig")

        custom_config.setConfigName(silent_pc3_name)
        custom_config.setCanonicalMediaName("ANSI_full_bleed_B_(11.00_x_17.00_Inches)")
        custom_config.setPlotType(Ax.AcPlotType.acExtents)
        custom_config.setCenterPlot(True)
        custom_config.setUseStandardScale(True)
        custom_config.setStandardScale(Ax.AcPlotScale.acScaleToFit)
        custom_config.refreshPlotDeviceInfo()

        temp_files = []
        output_dir = r"E:\TEMP"
        axDoc.setVariable("BACKGROUNDPLOT", 0)

        plot = axDoc.plot()
        idx = 0

        for lay in axDoc.layouts():
            if lay.name() == "Model":
                continue
            lay.copyFrom(custom_config)
            axDoc.setActiveLayout(lay)
            temp_pdf_path = os.path.join(output_dir, f"temp_split_{idx}.pdf")
            temp_files.append(temp_pdf_path)
            plot.plotToFile(temp_pdf_path, custom_config)
            print(f"Plotted layout: {lay.name()}")
            idx += 1

        custom_config.clear()
        if not temp_files:
            print("No paper space layouts were found to plot.")
            return

        print("Merging PDFs into a single document...")
        merger = PdfWriter()
        for temp_file in temp_files:
            if os.path.exists(temp_file):
                merger.append(temp_file)
        final_output = os.path.join(output_dir, "CombinedOutputs.pdf")
        merger.write(final_output)
        merger.close()
        
        # Clean up temporary split PDFs
        for temp_file in temp_files:
            try:
                os.remove(temp_file)
            except OSError:
                pass
            
        print(f"Success! Combined PDF saved to {final_output}")

    except Exception as err:
        traceback.print_exc()
        print(f"Error : {err}")
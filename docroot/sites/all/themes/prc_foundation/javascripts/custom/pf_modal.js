/**
 * Resize and adjustment placement of modal.  Call this after ajax so that the modal can adjust to the content.
 */
//Allow ajax to instruct that the window be resized
if (typeof Drupal.ajax != "undefined") {
  Drupal.ajax.prototype.commands.prcResizeModal = function () {
    modalContentResize();
  }
}